# $NetBSD: Makefile,v 1.2 2023/10/28 20:53:25 bacon Exp $

DISTNAME=	npmount-0.1.1.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	e0c8050286b01c8b6b70a6c773457753e5a7a567

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
