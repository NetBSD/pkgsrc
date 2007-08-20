# $NetBSD: Makefile,v 1.1.1.1 2007/08/20 11:59:17 jmmv Exp $
#

DISTNAME=	atf-0.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jmmv/atf/0.1/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/~jmmv/atf/
COMMENT=	Automated testing framework

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	ATF_CONFSUBDIR=
CONFIGURE_ARGS+=	ATF_SHELL=${SH:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	atf

.include "../../mk/bsd.pkg.mk"
