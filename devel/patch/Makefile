# $NetBSD: Makefile,v 1.8 2001/12/04 09:14:41 seb Exp $
#

DISTNAME=	patch-2.5.4
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=patch/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/patch/patch.html
COMMENT=	Patch files using diff output

NO_PATCH=	yes
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--program-prefix=g
PROGRAM_PREFIX=		g
.else
PROGRAM_PREFIX=
.endif

PLIST_SUBST+=		PROGRAM_PREFIX=${PROGRAM_PREFIX}

post-extract:
	${MV} ${WRKSRC}/pch.c ${WRKSRC}/pch.c.orig
	${SED}  -e '/#include <pch.h>/a\' -e '#include <sys/param.h>'	\
		-e 's/^#if HAVE_SETMODE/#if defined(HAVE_SETMODE) \&\& (!(defined(BSD) \&\& BSD >= 199306))/' \
		< ${WRKSRC}/pch.c.orig 					\
		> ${WRKSRC}/pch.c

.include "../../mk/bsd.pkg.mk"

# Needed for bootstrapping pkgsrc!
.if !exists(${GTAR})
GTAR=		/usr/bin/tar		# Solaris
.endif
