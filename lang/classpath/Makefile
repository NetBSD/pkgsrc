# $NetBSD: Makefile,v 1.5 2004/03/07 21:31:09 jmmv Exp $

DISTNAME=		classpath-0.07
CATEGORIES=		devel
MASTER_SITES=		ftp://alpha.gnu.org/gnu/classpath/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/classpath
COMMENT=		Class libraries for Java VM

DEPENDS+=		jikes>=1.18:../../lang/jikes

GNU_CONFIGURE=		yes
INFO_FILES=		hacking.info vmintegration.info
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-jikes

BUILDLINK_FILES.libart2+=	bin/libart2-config
BUILDLINK_TRANSFORM.libart2+=	-e 's|/libart2-config|/libart-config|g'

.include "../../graphics/libart2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
