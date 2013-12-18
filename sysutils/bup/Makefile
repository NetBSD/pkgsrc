# $NetBSD: Makefile,v 1.11 2013/12/18 23:48:22 wiz Exp $

DISTNAME=	bup-0.25rc1
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	# manually packaged since master site is git repository
# and only available via https
# https://github.com/apenwarr/bup/tarball/
# doc tarball: switch to "man" branch before downloading
# latest apenwarr doc tarball is for 0.24b
# bup-man-0.24b.tar.gz
# use lelutin one instead
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} lelutin-bup-7e0bc2e.zip
# ${DISTNAME:S/bup/bup-man/}${EXTRACT_SUFX}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://github.com/apenwarr/bup
COMMENT=	Highly efficient file backup system based on the git packfile format
LICENSE=	gnu-gpl-v2

DEPENDS+=	par2-[0-9]*:../../archivers/par2
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

# needs changing on each update
DOCDIR=		${WRKDIR}/lelutin-bup-7e0bc2e
WRKSRC=		${WRKDIR}/apenwarr-bup-4525252

TEST_TARGET=	test

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	PYTHON=${PYTHONBIN}
MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

USE_TOOLS+=		gmake perl
REPLACE_PERL=		format-subst.pl wvtestrun
REPLACE_PYTHON+=	cmd/bloom-cmd.py
REPLACE_PYTHON+=	cmd/daemon-cmd.py
REPLACE_PYTHON+=	cmd/damage-cmd.py
REPLACE_PYTHON+=	cmd/drecurse-cmd.py
REPLACE_PYTHON+=	cmd/fsck-cmd.py
REPLACE_PYTHON+=	cmd/ftp-cmd.py
REPLACE_PYTHON+=	cmd/fuse-cmd.py
REPLACE_PYTHON+=	cmd/help-cmd.py
REPLACE_PYTHON+=	cmd/index-cmd.py
REPLACE_PYTHON+=	cmd/init-cmd.py
REPLACE_PYTHON+=	cmd/join-cmd.py
REPLACE_PYTHON+=	cmd/list-idx-cmd.py
REPLACE_PYTHON+=	cmd/ls-cmd.py
REPLACE_PYTHON+=	cmd/margin-cmd.py
REPLACE_PYTHON+=	cmd/memtest-cmd.py
REPLACE_PYTHON+=	cmd/meta-cmd.py
REPLACE_PYTHON+=	cmd/midx-cmd.py
REPLACE_PYTHON+=	cmd/mux-cmd.py
REPLACE_PYTHON+=	cmd/newliner-cmd.py
REPLACE_PYTHON+=	cmd/on--server-cmd.py
REPLACE_PYTHON+=	cmd/on-cmd.py
REPLACE_PYTHON+=	cmd/random-cmd.py
REPLACE_PYTHON+=	cmd/restore-cmd.py
REPLACE_PYTHON+=	cmd/save-cmd.py
REPLACE_PYTHON+=	cmd/server-cmd.py
REPLACE_PYTHON+=	cmd/split-cmd.py
REPLACE_PYTHON+=	cmd/tag-cmd.py
REPLACE_PYTHON+=	cmd/tick-cmd.py
REPLACE_PYTHON+=	cmd/version-cmd.py
REPLACE_PYTHON+=	cmd/web-cmd.py
REPLACE_PYTHON+=	cmd/xstat-cmd.py
REPLACE_PYTHON+=	lib/tornado/__init__.py
REPLACE_PYTHON+=	lib/tornado/auth.py
REPLACE_PYTHON+=	lib/tornado/autoreload.py
REPLACE_PYTHON+=	lib/tornado/database.py
REPLACE_PYTHON+=	lib/tornado/escape.py
REPLACE_PYTHON+=	lib/tornado/httpclient.py
REPLACE_PYTHON+=	lib/tornado/httpserver.py
REPLACE_PYTHON+=	lib/tornado/httputil.py
REPLACE_PYTHON+=	lib/tornado/ioloop.py
REPLACE_PYTHON+=	lib/tornado/iostream.py
REPLACE_PYTHON+=	lib/tornado/locale.py
REPLACE_PYTHON+=	lib/tornado/options.py
REPLACE_PYTHON+=	lib/tornado/s3server.py
REPLACE_PYTHON+=	lib/tornado/template.py
REPLACE_PYTHON+=	lib/tornado/test/test_ioloop.py
REPLACE_PYTHON+=	lib/tornado/web.py
REPLACE_PYTHON+=	lib/tornado/websocket.py
REPLACE_PYTHON+=	lib/tornado/wsgi.py
REPLACE_PYTHON+=	main.py
REPLACE_PYTHON+=	wvtest.py

post-install:
	${INSTALL_DATA} ${DOCDIR}/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/DESIGN ${DESTDIR}${PREFIX}/share/doc/bup
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/bup

.include "../../filesystems/py-fuse-bindings/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
