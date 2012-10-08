# $NetBSD: Makefile,v 1.2 2012/10/08 09:57:20 asau Exp $
#

PKGNAME=	ec2-api-tools-1.3.62308
DISTNAME=	ec2-api-tools-1.3-62308

.include	"Makefile.common"

CATEGORIES=	misc
MASTER_SITES=	http://s3.amazonaws.com/ec2-downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	http://aws.amazon.com/developertools/351
COMMENT=	Amazon EC2 API tools (register, launch, administer instances)
LICENSE=	amazon-software-license AND apache-2.0 AND gnu-gpl-v2 \
		    AND cddl-1.0

NO_BUILD=	yes

USE_JAVA=	run
USE_JAVA2=	1.5

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/usr/bin/env.*bash
REPLACE.bash.new=	/bin/sh
REPLACE_FILES.bash=	bin/*

SUBST_CLASSES+=		java-path
SUBST_STAGE.java-path=	pre-configure
SUBST_FILES.java-path=	bin/ec2-cmd
SUBST_VARS.java-path+=	PKG_JAVA_HOME
SUBST_MESSAGE.java-path=Fixing path to Java interpreter.

SUBST_CLASSES+=		ec2-home
SUBST_STAGE.ec2-home=	pre-configure
SUBST_FILES.ec2-home=	bin/*
SUBST_SED.ec2-home+=	-e 's|:.EC2_HOME is not set|:-${EC2_HOME}|g'
SUBST_MESSAGE.ec2-home=	Setting EC2_HOME default path.

PLIST_SUBST+=		EC2_DIR=${EC2_DIR:Q}

INSTALLATION_DIRS+=	bin ${EC2_DIR} ${EC2_DIR}/bin ${EC2_DIR}/lib

post-extract:
	# Get rid of Windows batch files
	${FIND} ${WRKSRC} -name \*.cmd -type f -print | ${XARGS} ${RM} -f

do-install:
	${FIND} ${WRKSRC} -name \*.orig -type f -print | ${XARGS} ${RM} -f

	# Install EC2 .jar files
	cd ${WRKSRC}/lib && for f in *; do			\
	       ${INSTALL_DATA} $$f ${DESTDIR}${EC2_HOME}/lib;	\
	done

	# Install EC2 scripts
	cd ${WRKSRC}/bin && for f in *; do			\
		${INSTALL_SCRIPT} $$f ${DESTDIR}${EC2_HOME}/bin;\
		${LN} -sf ${DESTDIR}${EC2_HOME}/bin/$$f 	\
			${DESTDIR}${PREFIX}/bin;		\
	done


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
