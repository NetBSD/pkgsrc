# $NetBSD: Makefile,v 1.8 2003/07/31 22:58:39 seb Exp $

DISTNAME=		algae-4.1.3
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=algae/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://algae.sourceforge.net/
COMMENT=		Interpreted language for numerical analysis

DEPENDS+=		gnuplot>=3.5:../../graphics/gnuplot

GNU_CONFIGURE=		# defined
USE_FORTRAN=		# defined
USE_BUILDLINK2=		# defined
USE_GNU_READLINE=	# uses history_truncate_file

USE_NEW_TEXINFO=	YES
INFO_FILES=		algae.info

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
