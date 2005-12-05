# $NetBSD: Makefile,v 1.9 2005/12/05 20:50:26 rillig Exp $

DISTNAME=		ksi-3.4.1
PKGREVISION=		3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ksi/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ksi.sourceforge.net/
COMMENT=		Portable, embeddable Scheme implementation written in C

CPPFLAGS+=		-Dunix
GNU_CONFIGURE=		yes
INFO_FILES=		ksi-lang.info ksi-lib.info ksi.info
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR:Q}
USE_GNU_READLINE=	# uses rl_event_hook() interface
USE_LIBTOOL=		yes
USE_MAKEINFO=		YES
USE_NEW_TEXINFO=	YES
USE_PKGLOCALEDIR=	yes

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
