# $NetBSD: Makefile,v 1.6 2016/03/13 09:36:58 taca Exp $
#

PKGNAME=	ec2-ami-tools-1.3.57676
DISTNAME=	ec2-ami-tools-1.3-57676
PKGREVISION=	3

.include "../../misc/ec2-api-tools/Makefile.common"

CATEGORIES=	misc
MASTER_SITES=	http://s3.amazonaws.com/ec2-downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	http://aws.amazon.com/developertools/368
COMMENT=	Amazon EC2 AMI Tools (bundle, create, upload AMIs to S3)
LICENSE=	amazon-software-license

USE_TOOLS=	bash:run gtar:run gzip:run openssl:run pax tee:run

DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	${RUBY_BASE}>=1.8.2:${RUBY_SRCDIR}

NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	/bin/sh
REPLACE_FILES.bash=	bin/*

SUBST_CLASSES+=		ec2-home
SUBST_STAGE.ec2-home=	pre-configure
SUBST_FILES.ec2-home=	bin/*
SUBST_SED.ec2-home+=	-e 's|\$${EC2_HOME.*}|${EC2_HOME}}|g'
SUBST_MESSAGE.ec2-home=	Setting EC2_HOME default path for scripts.

SUBST_CLASSES+=		ruby
SUBST_STAGE.ruby=	pre-configure
SUBST_FILES.ruby=	bin/*
SUBST_SED.ruby+=	-e 's|^ruby |${RUBY_NAME} |g'
SUBST_MESSAGE.ruby=	Fixing ruby interpreter name.

SUBST_CLASSES+=		ec2-rb
SUBST_STAGE.ec2-rb=	pre-configure
SUBST_FILES.ec2-rb+=	lib/ec2/common/curl.rb
SUBST_FILES.ec2-rb+=	lib/ec2/platform/netbsd/constants.rb
SUBST_VARS.ec2-rb+=	EC2_HOME
SUBST_MESSAGE.ec2-rb=	Setting EC2_HOME constant for EC2 Ruby modules.

PLIST_SUBST+=		EC2_DIR=${EC2_DIR:Q}

INSTALLATION_DIRS+=	bin ${EC2_DIR}
INSTALLATION_DIRS+=	${EC2_DIR}/etc ${EC2_DIR}/bin ${EC2_DIR}/lib

post-extract:
	# Create and copy the NetBSD Ruby modules
	${MKDIR} ${WRKSRC}/lib/ec2/platform/netbsd/
	${CP} ${FILESDIR}/netbsd.rb ${WRKSRC}/lib/ec2/platform/
	${CP} ${FILESDIR}/netbsd/*.rb ${WRKSRC}/lib/ec2/platform/netbsd/

	find ${WRKSRC}/lib ${WRKSRC}/etc -type d -exec \
		${CHMOD} ${PKGDIRMODE} {} \;
	find ${WRKSRC}/lib ${WRKSRC}/etc -type f -exec \
		${CHMOD} ${NONBINMODE} {} \;

do-install:
	${FIND} ${WRKSRC} -name \*.orig -type f -print | ${XARGS} ${RM} -f

	cd ${WRKSRC}/etc && pax -rwpam . ${DESTDIR}${EC2_HOME}/etc
	cd ${WRKSRC}/lib && pax -rwpam . ${DESTDIR}${EC2_HOME}/lib

	cd ${WRKSRC}/bin && for f in *; do			\
		${INSTALL_SCRIPT} $$f ${DESTDIR}${EC2_HOME}/bin;\
		${LN} -sf ${DESTDIR}${EC2_HOME}/bin/$$f		\
			${DESTDIR}${PREFIX}/bin;		\
	done

.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
