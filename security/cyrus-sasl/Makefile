# $NetBSD: Makefile,v 1.1.1.1 2000/08/25 15:23:49 jlam Exp $

DISTNAME=	cyrus-sasl-1.5.24
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

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

post-build:
	${CAT} ${PKGDIR}/PLIST.common ${PKGDIR}/PLIST.${LOWER_OPSYS} > ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
