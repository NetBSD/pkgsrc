# $NetBSD: Makefile,v 1.8 2012/09/11 23:19:40 asau Exp $
#

DISTNAME=	tinderbox-dragonfly-${TBOX_VERSION}
PKGREVISION=	3
CATEGORIES=	pkgtools
MASTER_SITES=	http://tinderbox.marcuscom.com/
DISTFILES=	tinderbox-${TBOX_VERSION}.tar.gz

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://tinderbox.marcuscom.com/
COMMENT=	Tinderbox package building system (pkgsrc)
LICENSE=	modified-bsd

DEPENDS+=	p5-Compress-Bzip2>=2:../../archivers/p5-Compress-Bzip2
DEPENDS+=	csup>=20100101:../../net/csup
DEPENDS+=	scmgit>1.6:../../devel/scmgit

TBOX_VERSION=		3.4.1
ONLY_FOR_PLATFORM=	DragonFly-*-*

USE_TOOLS+=		perl perl:run
NO_CONFIGURE=		yes
NO_BUILD=		yes
RCD_SCRIPTS=		tinderd
WRKSRC=			${WRKDIR}/tinderbox-${TBOX_VERSION}
TRASH=			${WRKDIR}/trash
MAN_FILES_cmd=		${SED} -ne "s,^man/man1/,,p" PLIST
MAN_FILES=		${MAN_FILES_cmd:sh}

INSTALLATION_DIRS+=	tinderbox/scripts
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	contrib/bulk/add_all_packages.sh
SUBST_FILES.paths+=	contrib/bulk/bulk_hook_1.sh
SUBST_FILES.paths+=	contrib/bulk/bulkbuild.sh
SUBST_SED.paths+=	-e 's,@TINROOT@,${PREFIX}/tinderbox,g'
SUBST_STAGE.paths=	post-patch

.include "options.mk"

post-extract:
	${MKDIR} ${TRASH}
.if empty(PKG_OPTIONS:Mwebui)
	mv ${WRKSRC}/webui ${TRASH}
.endif
	mv ${WRKSRC}/etc/rc.d ${TRASH}
	${MKDIR} ${WRKSRC}/contrib/bulk
	for dossier in add_all_packages bulk_hook_1 bulkbuild; do \
		${CP} ${FILESDIR}/$${dossier}.sh.in \
		${WRKSRC}/contrib/bulk/$${dossier}.sh; \
	done
	chmod 755 ${WRKSRC}/contrib/bulk/*

post-patch:
.if !empty(PKG_OPTIONS:Manybody)
	perl -i -pe 's/^if \[ `id -u` != 0 \]; then/if false; then/' \
		${WRKSRC}/tc
.endif
	cd ${WRKSRC} && ${FIND} -E . -regex '.*(orig|bak)' -exec ${RM} {} \;

do-install:
	for manual in ${MAN_FILES}; do \
		${INSTALL_MAN} ${WRKSRC}/man/man1/$${manual} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1; \
	done
	mv ${WRKSRC}/man ${TRASH}
	cd ${WRKSRC}; for dossier in .version *; do \
		${TEST} ! -f "$$dossier" || \
		${CP} "$$dossier" ${DESTDIR}${PREFIX}/tinderbox/scripts; \
		${TEST} ! -d "$$dossier" || \
		${CP} -R "$$dossier" ${DESTDIR}${PREFIX}/tinderbox/scripts; \
	done

.include "../../mk/bsd.pkg.mk"
