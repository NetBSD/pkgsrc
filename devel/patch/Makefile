# $NetBSD: Makefile,v 1.10 2002/12/22 17:30:09 wiz Exp $
#

DISTNAME=	patch-2.5.4
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=patch/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/patch/patch.html
COMMENT=	Patch files using diff output

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
.endif

PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}

do-patch:
	${MV} ${WRKSRC}/pch.c ${WRKSRC}/pch.c.orig
	${AWK} '/#include <pch.h>/{print $$0 "\n#include <sys/param.h>";next;}\
		/^#if HAVE_SETMODE/					\
		{gsub(/^#if HAVE_SETMODE/,"#if defined(HAVE_SETMODE) \\&\\& (!(defined(BSD) \\&\\& BSD >= 199306))");print $$0; next; }			\
		{print $$0;}'						\
		< ${WRKSRC}/pch.c.orig 					\
		> ${WRKSRC}/pch.c

.include "../../mk/bsd.pkg.mk"

# Needed for bootstrapping pkgsrc!
.if !exists(${GTAR})
GTAR=		/usr/bin/tar		# Solaris
.endif
