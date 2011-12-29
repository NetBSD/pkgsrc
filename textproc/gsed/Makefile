# $NetBSD: Makefile,v 1.38 2011/12/29 22:30:47 sbd Exp $
#

DISTNAME=	sed-4.2.1
PKGNAME=	g${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sed/sed.html
COMMENT=	GNU implementation of sed, the POSIX stream editor
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.3

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
INFO_FILES=		YES
TEST_TARGET=		check

# at least Solaris-2.9 has issues with grep/egrep
USE_TOOLS+=		grep makeinfo

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

PLIST_VARS=		gsed
.if !defined(GNU_PROGRAM_PREFIX) || ${GNU_PROGRAM_PREFIX} != "g"
PLIST.gsed=		yes

post-install:
	${LN} -f ${DESTDIR}${PREFIX}/bin/${GNU_PROGRAM_PREFIX}sed ${DESTDIR}${PREFIX}/bin/gsed
	${LN} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${GNU_PROGRAM_PREFIX}sed.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gsed.1
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
