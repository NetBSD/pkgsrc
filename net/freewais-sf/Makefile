# $NetBSD: Makefile,v 1.30 2007/12/02 11:26:50 wiz Exp $
#

DISTNAME=	freeWAIS-sf-2.2.12
PKGNAME=	freewais-sf-2.2.12
PKGREVISION=	6
CATEGORIES=	net databases
MASTER_SITES=	ftp://ftp.informatik.uni-hamburg.de/pub/soft/infosystems/wais/freeWAIS/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.is.informatik.uni-duisburg.de/projects/freeWAIS-sf/
COMMENT=	Enhanced Wide Area Information Server

NOT_FOR_PLATFORM=	Darwin-*-*

USE_LIBTOOL=	yes
USE_TOOLS+=	makeinfo gzcat:run gzip:run perl:run

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q}
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX:Q}			\
			-Darchname=${MACHINE_ARCH}-${LOWER_OPSYS}	\
			-Dmansrc=${PREFIX:Q}/${PKGMANDIR:Q}/man1	\
			-Dgzip=${TOOLS_PATH.gzip:Q}			\
			-Dzcat=${TOOLS_PATH.gzcat:Q}
CONFIGURE_ENV+=		PERL5=${PERL5:Q}
INSTALL_TARGET=		install install.man
INFO_FILES=		# PLIST

post-build:
	cd ${WRKSRC}/doc/SF && makeinfo fwsf.texi

post-install:
	cd ${WRKSRC}/doc/SF; for f in fwsf.info fwsf.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done

.include "../../mk/bsd.pkg.mk"
