# $NetBSD: Makefile,v 1.20 2008/09/12 12:00:12 gdt Exp $
#

DISTNAME=		cdif-1.15
CATEGORIES=		textproc
MASTER_SITES=		http://www.srekcah.org/~utashiro/perl/scripts/cdif/
EXTRACT_SUFX=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.srekcah.org/~utashiro/perl/scripts/cdif/
COMMENT=		Word context diff

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=		cdif-license
RESTRICTED=		Redistribution only for "non-commercial purpose".
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

NOT_FOR_BULK_PLATFORM=	HPUX-*-*

WRKSRC=			${WRKDIR}
USE_TOOLS+=		perl:run

NO_CONFIGURE=		yes
NO_BUILD=		yes
INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/${DISTNAME}.dist

do-patch:
	${SED} -e '1s@/usr/local/bin/perl@${PERL5}@' \
		< ${WRKSRC}/${DISTNAME}.dist > ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/bin/cdif

.include "../../mk/bsd.pkg.mk"
