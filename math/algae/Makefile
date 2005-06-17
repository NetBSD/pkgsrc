# $NetBSD: Makefile,v 1.15 2005/06/17 12:56:04 kristerw Exp $

DISTNAME=		algae-4.1.3
PKGREVISION=		3
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=algae/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://algae.sourceforge.net/
COMMENT=		Interpreted language for numerical analysis

DEPENDS+=		gnuplot>=3.5:../../graphics/gnuplot

GNU_CONFIGURE=		yes
USE_LANGUAGES=		fortran
USE_GNU_READLINE=	# uses history_truncate_file

INFO_FILES=		algae.info

USE_TOOLS+=		ls tr
CONFIGURE_ENV+=		ac_cv_path_LS="${TOOLS_LS}"
CONFIGURE_ENV+=		ac_cv_path_TR="${TOOLS_TR}"

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
