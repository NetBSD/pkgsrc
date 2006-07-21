# $NetBSD: Makefile,v 1.20 2006/07/21 05:32:11 rillig Exp $

DISTNAME=		algae-4.1.3
PKGREVISION=		4
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=algae/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://algae.sourceforge.net/
COMMENT=		Interpreted language for numerical analysis

DEPENDS+=		gnuplot>=3.5:../../graphics/gnuplot

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c fortran
USE_TOOLS+=		ls tr
USE_GNU_READLINE=	yes	# uses history_truncate_file
INFO_FILES=		yes
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			mandir=${PREFIX:Q}/${PKGMANDIR:Q}/man1		\
			infodir=${PREFIX:Q}/${PKGINFODIR:Q}		\
			htmldir=${PREFIX:Q}/share/doc/html/algae	\
			sourcedir=${PREFIX:Q}/include			\
			hdir=${PREFIX:Q}/include/algae

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
