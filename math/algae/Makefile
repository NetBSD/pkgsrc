# $NetBSD: Makefile,v 1.2 2002/10/25 18:42:28 wiz Exp $

DISTNAME=		algae-3.6.2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=algae/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://algae.sourceforge.net/
COMMENT=		Interpreted language for numerical analysis

DEPENDS+=		gnuplot>=3.5:../../graphics/gnuplot

GNU_CONFIGURE=		# defined
USE_FORTRAN=		# defined
USE_BUILDLINK2=		# defined
USE_GNU_READLINE=	# uses history_truncate_file

INFO_FILES=		algae.info

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
