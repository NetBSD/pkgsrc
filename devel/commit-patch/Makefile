# $NetBSD: Makefile,v 1.1 2014/08/09 23:49:53 wiz Exp $

DISTNAME=	commit-patch-2.5
CATEGORIES=	devel scm
MASTER_SITES=	http://www.porkrind.org/commit-patch/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.porkrind.org/commit-patch/
COMMENT=	Commit patches to most common SCM repositories
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-IPC-Run-[0-9]*:../../devel/p5-IPC-Run
DEPENDS+=	patchutils-[0-9]*:../../devel/patchutils

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake perl:run pod2man
MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}
REPLACE_PERL+=	commit-partial
REPLACE_PERL+=	commit-patch

.include "../../mk/bsd.pkg.mk"
