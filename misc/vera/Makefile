# $NetBSD: Makefile,v 1.22 2017/09/06 10:40:31 wiz Exp $

DISTNAME=	vera-1.21a
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=vera/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://cgi.snafu.de/ohei/user-cgi-bin/veramain-e.cgi
COMMENT=	Virtual Entity of Relevant Acronyms
LICENSE=	gnu-fdl-v1.3

USE_TOOLS+=	makeinfo
INFO_FILES=	yes

INSTALLATION_DIRS=	${PKGINFODIR}

do-build:
	cd ${WRKSRC} && makeinfo vera.texi

do-install:
	cd ${WRKSRC}; for f in vera.info vera.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};\
	done

.include "../../mk/bsd.pkg.mk"
