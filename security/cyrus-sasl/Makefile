# $NetBSD: Makefile,v 1.3 2000/10/25 08:00:24 rh Exp $

DISTNAME=	cyrus-sasl-1.5.24
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://asg.web.cmu.edu/cyrus/imapd/

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

.include "../../mk/bsd.prefs.mk"

.if !exists(/usr/include/openssl/rc4.h)
DEPENDS+=	openssl-0.9.*:../../security/openssl
CONFIGURE_ENV+=	CPPFLAGS="-I${PREFIX}/include"
.else
CONFIGURE_ENV+=	CPPFLAGS="-I/usr/include/openssl"
.endif

CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/sasl

.if defined(USE_PAM)
CONFIGURE_ARGS+=	--with-pam=${PREFIX}
DEPENDS+=		PAM-*:../../security/PAM
.endif
.if defined(CYRUS_USE_PWCHECK)
CONFIGURE_ARGS+=	--with-pwcheck
.endif
.if defined(KERBEROS) && (${KERBEROS} == 4)
CONFIGURE_ARGS+=	--enable-krb4
DEPENDS+=		kth-krb4-*:../../security/kth-krb4
.else
CONFIGURE_ARGS+=	--disable-krb4
.endif

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

post-build:
	${ECHO} > ${PLIST_SRC}
.if defined(CYRUS_USE_PWCHECK)
	${CAT} ${PKGDIR}/PLIST.pwcheck >> ${PLIST_SRC}
.endif
.if defined(KERBEROS) && (${KERBEROS} == 4)
	${CAT} ${PKGDIR}/PLIST.krb4 >> ${PLIST_SRC}
.endif
	${CAT} ${PKGDIR}/PLIST.common ${PKGDIR}/PLIST.${LOWER_OPSYS} >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
