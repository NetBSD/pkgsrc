# $NetBSD: Makefile,v 1.13 2004/04/21 21:09:33 cube Exp $

DISTNAME=	cyrus-sasl-2.1.18
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

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://asg.web.cmu.edu/sasl/
COMMENT=		Cyrus SASL plaintext authentication daemon

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
PLIST_SRC=		${PKGDIR}/PLIST

ALL_TARGET=		all saslcache testsaslauthd

BUILD_DEFS+=		USE_PAM USE_OPENLDAP SASL_USE_GSSAPI

SASLSOCKETDIR?=		/var/run/saslauthd
BUILD_DEFS+=		SASLSOCKETDIR
FILES_SUBST+=		SASLSOCKETDIR=${SASLSOCKETDIR}
CONFIGURE_ARGS+=	--with-saslauthd="${SASLSOCKETDIR}"

.if defined(USE_PAM)
.  include "../../security/PAM/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam=${BUILDLINK_PREFIX.pam}
.endif

.if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[Yy][Ee][Ss])
.  include "../../databases/openldap/buildlink3.mk"
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.  include "../../security/openssl/buildlink3.mk"
BUILDLINK_INCDIRS.cyrus-sasl=	include/sasl
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
PLIST_SRC+=		${PKGDIR}/PLIST.ldap
.endif

.if defined(KERBEROS)
SASL_USE_GSSAPI=	yes
.endif
.if (defined(SASL_USE_GSSAPI) && !empty(SASL_USE_GSSAPI:M[yY][eE][sS]))
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit
.endif

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL
RCD_SCRIPTS=		saslauthd
FILES_SUBST+=		ROOT_USER=${ROOT_USER}

INSTALLATION_DIRS=	bin

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
.if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[Yy][Ee][Ss])
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cyrus-saslauthd
	${INSTALL_DATA} ${WRKSRC}/LDAP_SASLAUTHD \
		${PREFIX}/share/doc/cyrus-saslauthd
.endif

.include "../../mk/bsd.pkg.mk"
