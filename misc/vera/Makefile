# $NetBSD: Makefile,v 1.19 2012/10/08 09:57:40 asau Exp $

DISTNAME=	vera-1.16
CATEGORIES=	misc
MASTER_SITES=	http://home.snafu.de/ohei/FTP/ \
		${MASTER_SITE_GNU:=vera/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgi.snafu.de/ohei/user-cgi-bin/veramain-e.cgi
COMMENT=	Virtual Entity of Relevant Acronyms

USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST

INSTALLATION_DIRS=	${PKGINFODIR}

do-build:
	cd ${WRKSRC} && makeinfo vera.texi

do-install:
	cd ${WRKSRC}; for f in vera.info vera.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};\
	done

.include "../../mk/bsd.pkg.mk"
