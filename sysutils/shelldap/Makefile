# $NetBSD: Makefile,v 1.10 2013/12/09 14:17:52 obache Exp $
#

PKGNAME=	shelldap-0.5
DISTNAME=	c6a3abc56c74
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://code.martini.nu/shelldap/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://projects.martini.nu/shelldap
COMMENT=	Shell-like interface for browsing LDAP servers
LICENSE=	modified-bsd

DEPENDS+=	p5-YAML-Syck>=1.15:../../textproc/p5-YAML-Syck
DEPENDS+=	p5-Term-Shell>=0.02:../../devel/p5-Term-Shell
DEPENDS+=	{perl>=5.13.6,p5-Digest-MD5>=2.51}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Algorithm-Diff>=1.1902:../../devel/p5-Algorithm-Diff
DEPENDS+=	p5-perl-ldap>=0.40.01:../../databases/p5-perl-ldap
DEPENDS+=	p5-Term-ReadLine>=1.20:../../devel/p5-Term-ReadLine

WRKSRC=		${WRKDIR}/shelldap-c6a3abc56c74
USE_LANGUAGES=	# none

NO_BUILD=	yes
REPLACE_PERL+=	shelldap
USE_TOOLS+=	perl:run

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/shelldap ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
