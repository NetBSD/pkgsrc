# $NetBSD: Makefile,v 1.1.1.1 2007/06/11 03:42:06 minskim Exp $

DISTNAME=	hoe-1.2.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/20912/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/hoe/
COMMENT=	Rake extension to provide full project automation

DEPENDS+=	rake-[0-9]*:../../devel/rake
DEPENDS+=	rubyforge-[0-9]*:../../devel/rubyforge
DEPENDS+=	rubygems-[0-9]*:../../misc/rubygems

NO_BUILD=	yes
USE_LANGUAGES=	# none

REPLACE_RUBY=	bin/sow

FIND_PREFIX:=	RAKE_PREFIX=rake
.include "../../mk/find-prefix.mk"

.include "../../lang/ruby/modules.mk"

do-install:
	cd ${WRKSRC} && ${RAKE_PREFIX}/bin/rake install

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/hoe
	${INSTALL_DATA} ${WRKSRC}/README.txt ${RUBY_DOCDIR}/hoe

.include "../../mk/bsd.pkg.mk"
