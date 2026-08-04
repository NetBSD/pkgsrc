# $NetBSD: Makefile,v 1.21 2026/08/04 20:29:03 wiz Exp $
#

DISTNAME=	regina397
PKGNAME=	rexx-regina-3.9.7
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regina-rexx/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://regina-rexx.sourceforge.io/
COMMENT=	Implementation of the REXX language
LICENSE=	gnu-lgpl-v2	# or higher

CONFLICTS=	rexx-imc-[0-9]* oorexx-[0-9]*

MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONF_FILES+=		share/regina/examples/rxstack.conf ${PKG_SYSCONFDIR}/rxstack.conf

INSTALL_MAKE_FLAGS+=	sharedir=${PREFIX}/share/regina

REPLACE_INTERPRETER+=	regina
REPLACE.regina.old=	regina
REPLACE.regina.new=	${PREFIX}/bin/regina
REPLACE_FILES.regina=	demo/*.rexx regutil/*.rexx

REPLACE_INTERPRETER+=	rexx
REPLACE.rexx.old=	/usr/bin/rexx
REPLACE.rexx.new=	${PREFIX}/bin/rexx
REPLACE_FILES.rexx=	demo/*.rexx

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	pre-configure
SUBST_MESSAGE.etc=	Fixing etc directory path
SUBST_FILES.etc=	rxstack.c
SUBST_SED.etc=		-e 's;/etc/;${PKG_SYSCONFDIR}/;'

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
