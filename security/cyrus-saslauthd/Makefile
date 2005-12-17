# $NetBSD: Makefile,v 1.27 2005/12/17 05:20:23 jlam Exp $

DISTNAME=	cyrus-sasl-2.1.20
PKGNAME=	${DISTNAME:S/sasl/saslauthd/}
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/sasl/

CONFLICTS+=	cyrus-sasl<2.1.15nb2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/${DISTNAME}/saslauthd
EXTRACT_ELEMENTS=	${DISTNAME}/saslauthd
EXTRACT_ELEMENTS+=	${DISTNAME}/include/hmac-md5.h

MAINTAINER=		jlam@pkgsrc.org
HOMEPAGE=		http://asg.web.cmu.edu/sasl/
COMMENT=		Cyrus SASL plaintext authentication daemon

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

BUILD_TARGET=		all saslcache testsaslauthd

SASLSOCKETDIR?=		${VARBASE}/run/saslauthd
BUILD_DEFS+=		SASLSOCKETDIR
FILES_SUBST+=		SASLSOCKETDIR=${SASLSOCKETDIR:Q}
CONFIGURE_ARGS+=	--with-saslauthd=${SASLSOCKETDIR:Q}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

.include "options.mk"

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL
RCD_SCRIPTS=		saslauthd
FILES_SUBST+=		ROOT_USER=${ROOT_USER:Q}

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
