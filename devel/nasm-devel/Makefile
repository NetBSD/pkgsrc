# $NetBSD: Makefile,v 1.1.1.1 2001/06/20 16:43:01 wiz Exp $
#

DISTNAME=	nasm-0.98.08
CATEGORIES=	devel lang
MASTER_SITES=	ftp://nasm.2y.net/nasm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://nasm.2y.net/
COMMENT=	General-purpose x86 assembler

BUILD_DEPENDS+=	perl>=5.0:../../lang/perl5

INSTALL_TARGET=	install_everything
USE_GMAKE=	yes
INFO_FILES=	nasm.info

MAKE_ENV+=	PREFIX="${PREFIX}"			\
		PERL5="${PERL5}"			\
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"	\
		INSTALL_DATA="${INSTALL_DATA}"

.include "../../mk/bsd.pkg.mk"
