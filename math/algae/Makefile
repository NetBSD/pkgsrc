# $NetBSD: Makefile,v 1.24 2010/07/30 10:36:27 asau Exp $

DISTNAME=		algae-4.3.6
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=algae/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://algae.sourceforge.net/
COMMENT=		Interpreted language for numerical analysis

DEPENDS+=		gnuplot>=3.5:../../graphics/gnuplot

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-dlmalloc
CONFIGURE_ENV=		ac_cv_path_XTERM=xterm
USE_LANGUAGES=		c fortran77
USE_GNU_READLINE=	yes	# uses history_truncate_file
INFO_FILES=		yes
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			mandir=${PREFIX}/${PKGMANDIR}/man1		\
			infodir=${PREFIX}/${PKGINFODIR}		\
			htmldir=${PREFIX}/share/doc/algae

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
