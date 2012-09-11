# $NetBSD: Makefile,v 1.25 2012/09/11 23:04:16 asau Exp $

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
USE_GNU_READLINE=	yes	# uses history_truncate_file
INFO_FILES=		yes
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			mandir=${PREFIX}/${PKGMANDIR}/man1		\
			infodir=${PREFIX}/${PKGINFODIR}		\
			htmldir=${PREFIX}/share/doc/algae

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
