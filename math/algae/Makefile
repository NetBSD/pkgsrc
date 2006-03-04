# $NetBSD: Makefile,v 1.18 2006/03/04 21:30:02 jlam Exp $

DISTNAME=		algae-4.1.3
PKGREVISION=		4
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=algae/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://algae.sourceforge.net/
COMMENT=		Interpreted language for numerical analysis

DEPENDS+=		gnuplot>=3.5:../../graphics/gnuplot

GNU_CONFIGURE=		yes
USE_LANGUAGES=		fortran
USE_TOOLS+=		ls tr
USE_GNU_READLINE=	# uses history_truncate_file

INFO_FILES=		algae.info

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
