# $NetBSD: Makefile,v 1.1 2023/06/17 15:21:45 bacon Exp $

DISTNAME=	npmount-0.1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	61db68f8c8f14eeb7798b06578a34512c1a5574f

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/npmount
COMMENT=	Command line tool for non-privileged [un]mount
LICENSE=	2-clause-bsd

EGDIR=		${PREFIX}/share/examples/npmount
CONF_FILES=	${EGDIR}/npmount.conf.sample ${PREFIX}/etc/npmount.conf

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|g'
SUBST_FILES.prefix=	npmount.c

SPECIAL_PERMS+=		bin/npmount ${SETUID_ROOT_PERMS}
INSTALLATION_DIRS=	bin

post-install:
	${MKDIR} ${DESTDIR}${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/etc/npmount.conf.sample ${DESTDIR}${EGDIR}

.include "../../devel/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
