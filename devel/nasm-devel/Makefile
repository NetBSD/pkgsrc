# $NetBSD: Makefile,v 1.3.2.1 2002/06/23 18:44:35 jlam Exp $
#

DISTNAME=	nasm-0.98.08
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nasm/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://nasm.2y.net/
COMMENT=	General-purpose x86 assembler (development version)

BUILD_DEPENDS+=	perl>=5.0:../../lang/perl5

INSTALL_TARGET=	install_everything
USE_GMAKE=	yes
INFO_FILES=	nasm.info
TEXINFO_OVERRIDE=	YES
TEXINFO_PATTERNS+=	Makefile

MAKE_ENV+=	PREFIX="${PREFIX}"			\
		PERL5="${PERL5}"			\
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"	\
		INSTALL_DATA="${INSTALL_DATA}"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
