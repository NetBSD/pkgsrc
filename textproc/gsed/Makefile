# $NetBSD: Makefile,v 1.65 2024/05/01 22:44:09 cheusov Exp $

DISTNAME=	sed-4.9
PKGNAME=	g${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}
EXTRACT_SUFX=	.tar.xz

# Building the proper man page needs perl, but perl needs sed to build
# When updating, please build with _MAINTAINER_MANPAGE=yes
# and upload the new man page (doc/sed.1).
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
.include "options.mk"

_MAINTAINER_MANPAGE?=	no
.if !empty(_MAINTAINER_MANPAGE:M[Yy][Ee][Ss])
MAKE_ENV+=		PKGSRC_MAINTAINER_MANPAGE=yes
USE_TOOLS+=		perl
.else
pre-build: non-maintainer-manpage
.PHONY: non-maintainer-manpage
non-maintainer-manpage:
	${RM} -f ${WRKSRC}/doc/sed.1
	${MV} ${WRKDIR}/g${DISTNAME}.1 ${WRKSRC}/doc/sed.1
	${TOUCH} ${WRKSRC}/doc/sed.1
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/sed.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gsed.1
.for g n in bin/gsed ${PKGGNUDIR}bin/sed ${PKGMANDIR}/man1/gsed.1 ${PKGGNUDIR}${PKGMANDIR}/man1/sed.1
	${LN} -sf ${PREFIX}/${g} ${DESTDIR}${PREFIX}/${n}
.endfor

.include "../../mk/bsd.pkg.mk"
