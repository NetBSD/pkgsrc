# $NetBSD: Makefile,v 1.4 2003/06/02 01:18:35 jschauma Exp $

DISTNAME=		algae-4.1.2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=algae/}

MAINTAINER=		tech-pkg@netbsd.org
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
