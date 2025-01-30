# $NetBSD: Makefile,v 1.27 2025/01/30 08:05:15 wiz Exp $

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
CONFIGURE_ENV+=		ac_cv_path_XTERM=xterm
CONFIGURE_ENV+=		ac_cv_prog_F77="gfortran -std=legacy"
USE_LANGUAGES=		c fortran77
INFO_FILES=		yes
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	infodir=${PREFIX}/${PKGINFODIR}
INSTALL_MAKE_FLAGS+=	htmldir=${PREFIX}/share/doc/algae

# uses history_truncate_file
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
