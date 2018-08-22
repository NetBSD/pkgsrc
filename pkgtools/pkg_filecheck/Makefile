# $NetBSD: Makefile,v 1.45 2018/08/22 09:46:11 wiz Exp $
#

PKGNAME=	pkg_filecheck-0.4
PKGREVISION=	7
CATEGORIES=	pkgtools devel

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.NetBSD.org/docs/pkgsrc/
COMMENT=	Check for files not owned by any package
LICENSE=	modified-bsd AND 2-clause-bsd

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run
USE_FEATURES=	fts_open

USE_FEATURES+=	nbcompat
NBCOMPAT_CONFIGURE_ARGS+= --enable-db

FILES_SUBST+=	PKG_DBDIR=${PKG_DBDIR:Q}
CONF_FILES=	${PREFIX}/share/examples/pkg_filecheck/pkg_filecheck.conf \
		${PKG_SYSCONFDIR}/pkg_filecheck.conf

INSTALLATION_DIRS= \
	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 share/examples/pkg_filecheck

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	builddb.pl builddb.1 pkg_filecheck.conf
SUBST_FILES.paths+=	pkg_filecheck.conf.5 pkg_filecheck.c pkg_filecheck.1
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@PERL5@,${PERL5},g'
SUBST_SED.paths+=	-e 's,@PKG_DBDIR@,${PKG_DBDIR},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	pre-configure

post-extract:
.for f in builddb.pl builddb.1 pkg_filecheck.conf pkg_filecheck.conf.5 \
	pkg_filecheck.c pkg_filecheck.1
	${CP} ${FILESDIR}/${f} ${WRKSRC}/${f}
.endfor

do-build:
	cd ${WRKSRC} \
	    && ${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} ${BDB_LIBS} \
		-o pkg_filecheck pkg_filecheck.c ${LIBS}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/builddb.pl ${DESTDIR}${PREFIX}/bin/builddb
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_filecheck ${DESTDIR}${PREFIX}/bin/pkg_filecheck
	${INSTALL_MAN} ${WRKSRC}/builddb.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/pkg_filecheck.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/pkg_filecheck.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/pkg_filecheck.conf \
		${DESTDIR}${PREFIX}/share/examples/pkg_filecheck/pkg_filecheck.conf

# Must use the same libdb as pkg_install, which means the nbcompat one.
#.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
