# $NetBSD: Makefile,v 1.3 2004/01/12 03:16:32 jlam Exp $

DISTNAME=	cyrus-sasl-2.1.17
PKGNAME=	${DISTNAME:S/sasl/saslauthd/}
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/sasl/

CONFLICTS+=	cyrus-sasl-[0-9]*

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

BUILD_DEFS+=		USE_PAM USE_LDAP SASL_USE_GSSAPI

# /var/run/saslauthd matches the default value in configure.
SASLSOCKETDIR=		/var/run/saslauthd
FILES_SUBST+=		SASLSOCKETDIR=${SASLSOCKETDIR}
CONFIGURE_ARGS+=	--with-saslauthd="${SASLSOCKETDIR}"

.if defined(USE_PAM)
.  include "../../security/PAM/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam=${BUILDLINK_PREFIX.pam}
.endif

.if defined(USE_LDAP)
.  include "../../databases/openldap/buildlink3.mk"
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
PLIST_SRC+=		${PKGDIR}/PLIST.ldap
.endif

.if defined(SASL_USE_GSSAPI) && !empty(SASL_USE_GSSAPI:M[yY][eE][sS])
CONFIGURE_ARGS+=	--enable-gssapi=/usr	# GSSAPI
.  if exists(/usr/include/krb5/krb5.h)
CPPFLAGS+=		-I/usr/include/krb5
.  endif
.endif

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL
RCD_SCRIPTS=		saslauthd

post-configure:
	${LN} -sf saslauthd.h ${WRKSRC}/config.h

post-build:
	cd ${WRKSRC}; for f in LDAP_SASLAUTHD saslauthd.mdoc; do	\
		${SED}	-e "s|/usr/local/etc/|${PKG_SYSCONFDIR}/|g"	\
			$$f > $$f.new;					\
		${MV} -f $$f.new $$f;					\
	done

.if defined(USE_LDAP)
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cyrus-saslauthd
	${INSTALL_DATA} ${WRKSRC}/LDAP_SASLAUTHD \
		${PREFIX}/share/examples/cyrus-saslauthd
.endif

.include "../../mk/bsd.pkg.mk"
