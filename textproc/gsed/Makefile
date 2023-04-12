# $NetBSD: Makefile,v 1.61 2023/04/12 11:20:40 wiz Exp $

DISTNAME=	sed-4.9
PKGNAME=	g${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}
EXTRACT_SUFX=	.tar.xz

# Building the proper man page needs perl, but perl needs sed to build
# When updating, please build with the following line commented in
# and upload the new man page (doc/sed.1).
#USE_TOOLS+=	perl
DISTFILES+=	${DEFAULT_DISTFILES} g${DISTNAME}.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/sed/sed.html
COMMENT=	GNU implementation of sed, the POSIX stream editor
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.3

USE_GCC_RUNTIME=	yes
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
INFO_FILES=		YES
TEST_TARGET=		check

INSTALLATION_DIRS=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

# at least Solaris-2.9 has issues with grep/egrep
USE_TOOLS+=		grep makeinfo

CONFIGURE_ARGS+=	--program-prefix=g

.include "../../mk/bsd.prefs.mk"

post-install:
	${INSTALL_DATA} ${DISTDIR}/g${DISTNAME}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sed.1
	${INSTALL_DATA} ${DISTDIR}/g${DISTNAME}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gsed.1
.for g n in bin/gsed ${PKGGNUDIR}bin/sed ${PKGMANDIR}/man1/gsed.1 ${PKGGNUDIR}${PKGMANDIR}/man1/sed.1
	${LN} -sf ${PREFIX}/${g} ${DESTDIR}${PREFIX}/${n}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
