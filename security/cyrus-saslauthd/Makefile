# $NetBSD: Makefile,v 1.1.1.1 2004/01/09 19:44:10 jlam Exp $

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

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cyrus-saslauthd
	${INSTALL_DATA} ${WRKSRC}/LDAP_SASLAUTHD \
		${PREFIX}/share/examples/cyrus-saslauthd

.include "../../mk/bsd.pkg.mk"
