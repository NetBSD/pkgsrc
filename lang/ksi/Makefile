# $NetBSD: Makefile,v 1.12 2006/03/05 16:27:26 jlam Exp $

DISTNAME=		ksi-3.4.1
PKGREVISION=		4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ksi/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ksi.sourceforge.net/
COMMENT=		Portable, embeddable Scheme implementation written in C

CPPFLAGS+=		-Dunix
GNU_CONFIGURE=		yes
USE_TOOLS+=		makeinfo
INFO_FILES=		ksi-lang.info ksi-lib.info ksi.info
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR:Q}
USE_GNU_READLINE=	# uses rl_event_hook() interface
USE_LIBTOOL=		yes
USE_NEW_TEXINFO=	YES
USE_PKGLOCALEDIR=	yes

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
