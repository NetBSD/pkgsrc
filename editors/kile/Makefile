# $NetBSD: Makefile,v 1.30 2005/05/26 14:31:42 markd Exp $

DISTNAME=		kile-1.8
CATEGORIES=		editors kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kile/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://kile.sourceforge.net/
COMMENT=		LaTeX source editor - TeX shell - Gnuplot front end

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PERL5=		build
GNU_CONFIGURE=		yes

REPLACE_PERL=		src/kile1.6_upd.pl \
			src/kile1.7_upd.pl

SUBST_CLASSES+=		docfix
SUBST_STAGE.docfix=	post-patch
SUBST_MESSAGE.docfix=	"Fixup doc directory names"
SUBST_FILES.docfix= \
	translations/da/doc/Makefile.in \
	translations/et/doc/Makefile.in \
	translations/it/doc/Makefile.in \
	translations/nl/doc/Makefile.in \
	translations/pt/doc/Makefile.in \
	translations/sv/doc/Makefile.in
SUBST_SED.docfix=	-e 's:(KDE_LANG)/doc:(KDE_LANG)/kile:g'

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/kdegraphics3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
