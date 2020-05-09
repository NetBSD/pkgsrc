# $NetBSD: Makefile,v 1.1 2020/05/09 19:07:00 leot Exp $

DISTNAME=	chibi-scheme-0.8.0
CATEGORIES=	lang
MASTER_SITES=	http://synthcode.com/scheme/chibi/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://synthcode.com/wiki/chibi-scheme
COMMENT=	Minimal Scheme Implementation for use as an Extension Language
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	chibi-scheme.pc.in

REPLACE_INTERPRETER+=		chibi-scheme
REPLACE.chibi-scheme.old=	chibi-scheme
REPLACE.chibi-scheme.new=	${PREFIX}/bin/chibi-scheme
REPLACE_FILES.chibi-scheme+=	tools/chibi-doc tools/chibi-ffi
REPLACE_FILES.chibi-scheme+=	tools/snow-chibi tools/snow-chibi.scm

CFLAGS.NetBSD+=	-D_KMEMUSER	# Needed for kinfo_proc in <sys/sysctl.h>

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_ENV+=		PREFIX=${PREFIX}

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
