# $NetBSD: Makefile,v 1.9 2019/08/11 13:21:56 wiz Exp $

DISTNAME=	moreutils-0.63
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://git.joeyh.name/index.cgi/moreutils.git/snapshot/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://joeyh.name/code/moreutils/
COMMENT=	Additional Unix utilities
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pod2man perl:run

BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

DEPENDS+=	p5-IPC-Run-[0-9]*:../../devel/p5-IPC-Run

USE_LANGUAGES=	c99

REPLACE_PERL+=	chronic
REPLACE_PERL+=	combine
REPLACE_PERL+=	ts
REPLACE_PERL+=	vidir
REPLACE_PERL+=	vipe
REPLACE_PERL+=	zrun

LDFLAGS.SunOS+=	-lsocket -lnsl

MAKE_ENV+=	\
	PREFIX=${PREFIX} \
	MANDIR=${PREFIX}/${PKGMANDIR} \
	CFLAGS=${CFLAGS:Q} \
	LDFLAGS=${LDFLAGS:Q} \
	DOCBOOKXSL=${PREFIX}/share/xsl/docbook \
	INSTALL_BIN=${INSTALL_PROGRAM:Q} \
	INSTALL_MAN=${INSTALL_MAN:Q} \
	INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}

# Avoid possible conflicts with `parallel' of parallel/parallel
post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/parallel \
	    ${DESTDIR}${PREFIX}/bin/moreutils-parallel
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/parallel.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/moreutils-parallel.1

.include "../../mk/bsd.pkg.mk"
