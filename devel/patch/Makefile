# $NetBSD: Makefile,v 1.23 2005/05/16 20:04:12 jlam Exp $
#

DISTNAME=	patch-2.5.4
PKGREVISION=	2
CATEGORIES=	devel

# We keep an uncompressed tar archive of the sources on
# ${MASTER_SITE_LOCAL} so that we won't need gzcat to extract the
# sources, which could potentially cause a circular dependency on
# archivers/gzip-base.
#
#MASTER_SITES=   ${MASTER_SITE_GNU:=patch/}
MASTER_SITES=   ${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/patch/patch.html
COMMENT=	Patch files using diff output

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.if !defined(GNU_PROGRAM_PREFIX) || ${GNU_PROGRAM_PREFIX} != "g"
PLIST_SUBST+=		PATCH_LINK=""
.else
PLIST_SUBST+=		PATCH_LINK="@comment "
.endif

do-patch:
	${MV} ${WRKSRC}/pch.c ${WRKSRC}/pch.c.orig
	${AWK} '/#include <pch.h>/{print $$0 "\n#include <sys/param.h>";next;}\
		/^#if HAVE_SETMODE/					\
		{gsub(/^#if HAVE_SETMODE/,"#if defined(HAVE_SETMODE) \\&\\& !(defined(BSD) \\&\\& BSD >= 199306) \\&\\& !defined(__INTERIX)");print $$0; next; } \
		{print $$0;}'						\
		< ${WRKSRC}/pch.c.orig 					\
		> ${WRKSRC}/pch.c

.if !defined(GNU_PROGRAM_PREFIX) || ${GNU_PROGRAM_PREFIX} != "g"
post-install:
	${LN} -sf ${GNU_PROGRAM_PREFIX}patch ${PREFIX}/bin/gpatch
.endif

.include "../../mk/bsd.pkg.mk"

.if empty(_USE_NEW_TOOLS:M[yY][eE][sS])
# Needed for bootstrapping pkgsrc!
.if !exists(${GTAR})
GTAR=		/usr/bin/tar		# Solaris
.endif
.endif
