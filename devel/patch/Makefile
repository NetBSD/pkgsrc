# $NetBSD: Makefile,v 1.38 2014/01/01 05:32:27 ryoon Exp $

DISTNAME=	patch-2.7.1
CATEGORIES=	devel
# We keep an uncompressed tar archive of the sources on
# ${MASTER_SITE_LOCAL} so that we won't need gzcat to extract the
# sources, which could potentially cause a circular dependency on
# archivers/gzip-base.
#
#MASTER_SITES=   ${MASTER_SITE_GNU:=patch/}
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/patch/patch.html
COMMENT=	Patch files using diff output
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_TOOLS+=		awk

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--program-prefix=g

INSTALLATION_DIRS=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

do-patch:
	${MV} ${WRKSRC}/src/pch.c ${WRKSRC}/src/pch.c.orig
	${AWK} '/#include <pch.h>/{print $$0 "\n#include <sys/param.h>";next;}\
		/^#if HAVE_SETMODE_DOS/					\
		{gsub(/^#if HAVE_SETMODE_DOS/,"#if defined(HAVE_SETMODE_DOS) \\&\\& !(defined(BSD) \\&\\& BSD >= 199306) \\&\\& !defined(__INTERIX)");print $$0; next; } \
		{print $$0;}'						\
		< ${WRKSRC}/src/pch.c.orig 					\
		> ${WRKSRC}/src/pch.c

SYMLINKS	= bin/gpatch ${PKGGNUDIR}bin/patch \
		man/man1/gpatch.1 ${PKGGNUDIR}${PKGMANDIR}/man1/patch.1
post-install:
.for o n in ${SYMLINKS}
	${LN} -sf ${PREFIX}/${o} ${DESTDIR}${PREFIX}/${n}
.endfor

.include "../../mk/bsd.pkg.mk"
