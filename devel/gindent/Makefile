# $NetBSD: Makefile,v 1.29 2003/06/02 01:20:47 jschauma Exp $
#

DISTNAME=	indent-2.2.8a
PKGNAME=	g${DISTNAME:S/a/.1/}
CATEGORIES=	devel
MASTER_SITES=	http://home.hccnet.nl/d.ingamells/
#MASTER_SITES=	${MASTER_SITE_GNU:=indent/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/indent/indent.html
COMMENT=	GNU version of pretty-printer for C source code

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined

INFO_FILES=	indent.info

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS=		--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=	GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=	GNU_PROGRAM_PREFIX

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
