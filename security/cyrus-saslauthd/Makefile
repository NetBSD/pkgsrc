# $NetBSD: Makefile,v 1.20 2004/10/03 00:18:08 tv Exp $

DISTNAME=	cyrus-sasl-2.1.19
PKGNAME=	${DISTNAME:S/sasl/saslauthd/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/sasl/

CONFLICTS+=	cyrus-sasl<2.1.15nb2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/${DISTNAME}/saslauthd
EXTRACT_ELEMENTS=	${DISTNAME}/saslauthd
EXTRACT_ELEMENTS+=	${DISTNAME}/include/hmac-md5.h

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://asg.web.cmu.edu/sasl/
COMMENT=		Cyrus SASL plaintext authentication daemon

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

ALL_TARGET=		all saslcache testsaslauthd

SASLSOCKETDIR?=		${VARBASE}/run/saslauthd
BUILD_DEFS+=		SASLSOCKETDIR
FILES_SUBST+=		SASLSOCKETDIR=${SASLSOCKETDIR}
CONFIGURE_ARGS+=	--with-saslauthd="${SASLSOCKETDIR}"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}

.include "options.mk"

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL
RCD_SCRIPTS=		saslauthd
FILES_SUBST+=		ROOT_USER=${ROOT_USER}

INSTALLATION_DIRS=	bin

.include "../../security/openssl/buildlink3.mk"

post-configure:
	${LN} -sf saslauthd.h ${WRKSRC}/config.h

post-build:
	cd ${WRKSRC}; for f in LDAP_SASLAUTHD saslauthd.mdoc; do	\
		${SED}	-e "s|/usr/local/etc/|${PKG_SYSCONFDIR}/|g"	\
			$$f > $$f.new;					\
		${MV} -f $$f.new $$f;					\
	done

post-install:
	for f in saslcache testsaslauthd; do				\
		${INSTALL_PROGRAM} ${WRKSRC}/$$f ${PREFIX}/bin/$$f;	\
	done
.if !empty(PKG_OPTIONS:Mldap)
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cyrus-saslauthd
	${INSTALL_DATA} ${WRKSRC}/LDAP_SASLAUTHD			\
		${PREFIX}/share/doc/cyrus-saslauthd
.endif

.include "../../mk/bsd.pkg.mk"
