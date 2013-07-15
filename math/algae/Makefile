# $NetBSD: Makefile,v 1.26 2013/07/15 02:02:25 ryoon Exp $

DISTNAME=		algae-4.3.6
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=algae/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://algae.sourceforge.net/
COMMENT=		Interpreted language for numerical analysis

DEPENDS+=		gnuplot>=3.5:../../graphics/gnuplot

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-dlmalloc
CONFIGURE_ENV=		ac_cv_path_XTERM=xterm
USE_LANGUAGES=		c fortran77
INFO_FILES=		yes
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			mandir=${PREFIX}/${PKGMANDIR}/man1		\
			infodir=${PREFIX}/${PKGINFODIR}		\
			htmldir=${PREFIX}/share/doc/algae

# uses history_truncate_file
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
