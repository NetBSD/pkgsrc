# $NetBSD: Makefile,v 1.26 2022/06/28 11:34:52 wiz Exp $
#

DISTNAME=	tds-1.4.2
PKGREVISION=	12
CATEGORIES=	misc www japanese
#MASTER_SITES=	http://tds.dive-in.to/dist/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://tds.dive-in.to/
COMMENT=	Web diary system

USE_TOOLS+=	perl:run
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PERL5=${PERL5:Q}

NO_BUILD=	YES

INSTALL_ENV+=	installdir=${DESTDIR}

REPLACE_PERL+=	*.pl */*.pl */*/*.pl web_diary_dir/*.cgi \
		web_diary_dir/admin/*.cgi

post-patch:
	@${FIND} ${WRKSRC} -type f -name '*.orig' -print | ${XARGS} ${RM} -f

.include "../../mk/bsd.pkg.mk"
