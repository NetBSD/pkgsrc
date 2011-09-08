# $NetBSD: Makefile,v 1.3 2011/09/08 21:57:55 wiz Exp $
#

DISTNAME=	bup-0.24b
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	# manually packaged since master site is git repository
# and only available via https
# https://github.com/apenwarr/bup/tarball/
# doc tarball: switch to "man" branch before downloading
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME:S/bup/bup-man/}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/apenwarr/bup
COMMENT=	Highly efficient file backup system based on the git packfile format
LICENSE=	gnu-gpl-v2

DEPENDS+=	par2-[0-9]*:../../archivers/par2
DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base

PKG_DESTDIR_SUPPORT=	user-destdir

# needs changing on each update
DOCDIR=		${WRKDIR}/apenwarr-bup-1783a57
WRKSRC=		${WRKDIR}/apenwarr-bup-d8d6406

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/bup

TEST_TARGET=	test

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

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
