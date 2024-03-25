# $NetBSD: Makefile,v 1.6 2024/03/25 15:16:32 nikita Exp $

DISTNAME=	remake-4.3+dbg-1.6
# upstream titles it 4.3.1
PKGNAME=	remake-4.3.1+dbg-1.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rocky/}
GITHUB_PROJECT=	remake
GITHUB_RELEASE=	remake-4.3+dbg-1.6

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://bashdb.sourceforge.net/remake/
COMMENT=	GNU make with comprehensible tracing and a debugger
LICENSE=	gnu-gpl-v3

USE_FEATURES=	snprintf

GNU_CONFIGURE=	yes
TEXINFO_REQD+=	4.0
INFO_FILES=	yes

TEST_TARGET=	check

# workaround for broken strndup
CONFIGURE_ARGS.MirBSD+=	ac_cv_func_strndup=no
CONFIGURE_ARGS=		--without-guile
# XXX: Do not install gmake setgid and do not override the owner group
# XXX: based on possible /dev/kmem permissions.
CONFIGURE_ARGS+=	ac_cv_func_getloadavg_setgid=no

# \todo: patch upstream.
post-install:
	${MV} ${DESTDIR}${PREFIX}/${PKGINFODIR}/make.info ${DESTDIR}${PREFIX}/${PKGINFODIR}/remake.info
	${MV} ${DESTDIR}${PREFIX}/${PKGINFODIR}/make.info-1 ${DESTDIR}${PREFIX}/${PKGINFODIR}/remake.info-1
	${MV} ${DESTDIR}${PREFIX}/${PKGINFODIR}/make.info-2 ${DESTDIR}${PREFIX}/${PKGINFODIR}/remake.info-2

# \todo: most of this package could probably be shorter if
# gmake had a Makefile file to re-use.

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
