# $NetBSD: Makefile,v 1.4 2004/02/14 17:21:43 jlam Exp $

DISTNAME=		ksi-3.4.1
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ksi/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ksi.sourceforge.net/
COMMENT=		Portable, embeddable Scheme implementation written in C

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_READLINE=	# uses rl_event_hook() interface
CPPFLAGS+=		-Dunix
USE_NEW_TEXINFO=	YES
USE_MAKEINFO=		YES
INFO_FILES=		ksi-lang.info ksi-lib.info ksi.info

.include "../../devel/boehm-gc/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
