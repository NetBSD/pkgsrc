# $NetBSD: Makefile,v 1.18 2025/12/25 16:43:30 adam Exp $

DISTNAME=	dash-0.5.13.1
CATEGORIES=	shells
MASTER_SITES=	http://gondor.apana.org.au/~herbert/dash/files/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://gondor.apana.org.au/~herbert/dash/
COMMENT=	Debian Almquist shell, POSIX-compliant shell faster than bash
LICENSE=	modified-bsd AND gnu-gpl-v2

USE_TOOLS+=		autoconf automake aclocal autoheader gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libedit
PKG_SHELL=		bin/dash

# Needed after patching configure.ac.
pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/editline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
