# $NetBSD: Makefile,v 1.1.1.1 2002/01/27 15:31:18 taca Exp $
#

DISTNAME=	xmlrpc4r-1_7_9
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME:S/_/./g}
CATEGORIES=	net
MASTER_SITES=	http://www.fantasy-coders.de/ruby/xmlrpc4r/

MAINTAINER=	neumann@s-direktnet.de
HOMEPAGE=	http://www.fantasy-coders.de/ruby/xmlrpc4r/
COMMENT=	implementation of the XML-RPC protocol for Ruby

#DEPENDS+=	${RUBY_PKGNAMEPREFIX}nqxml>=1.1.1:../../textproc/ruby-nqxml
DEPENDS+=	${RUBY_PKGNAMEPREFIX}nqxml>=1.1.1:../ruby-nqxml
DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	yes

DOC=		README ToDo doc/rubyStyle.css doc/ChangeLog.html \
		doc/base64.html doc/client.html doc/datetime.html \
		doc/howto.html doc/index.html doc/server.html 
EXAMPLES=	call.rb \
		chat/client.rb chat/client.rb.tk chat/server.rb \
		introspection/client.rb introspection/server.rb \
		marshallable/client.rb marshallable/person.rb \
		marshallable/server.rb \
		monitor/monitor.rb \
		multicall.rb perf_async.rb \
		raa/raa.rb raa/raa_fox.rb raa/raa_test.rb raa/raa_tk.rb \
		raa/responder.rb \
		sandstorm/active.rb \
		tcptunnel/README \
		validator/validator1.rb \
		webrick/client.rb webrick/server.rb \
		wwwsrv/srv.conf wwwsrv/srv.rb \
		xml.cgi xml.fcgi xml2.cgi
TESTS=		bench_parser.rb \
		files/bug_bool.expected files/bug_bool.xml \
		files/bug_covert.expected files/bug_covert.xml \
		files/fault.xml files/value.expected files/value.xml \
		files/xml1.expected files/xml1.xml \
		test_datetime.rb test_features.rb \
		test_marshal.rb test_parser.rb
REPLACE_RUBY=	redist/TCPSocketPipe.rb redist/dump.rb \
		samples/call.rb \
		samples/chat/client.rb samples/chat/client.rb.tk \
		samples/chat/server.rb \
		samples/introspection/client.rb \
		samples/introspection/server.rb \
		samples/marshallable/client.rb samples/marshallable/server.rb \
		samples/monitor/monitor.rb \
		samples/perf_async.rb \
		samples/raa/raa.rb samples/raa/raa_test.rb \
		samples/raa/raa_tk.rb \
		samples/validator/validator1.rb \
		samples/xml.cgi samples/xml.fcgi samples/xml2.cgi \
		test/bench_parser.rb test/test_datetime.rb \
		test/test_features.rb test/test_marshal.rb test/test_parser.rb

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/xmlrpc
.for f in ${DOC}
	${INSTALL_DATA} ${WRKSRC}/$f ${RUBY_DOCDIR}/xmlrpc
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlrpc/chat
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlrpc/introspection
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlrpc/marshallable
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlrpc/monitor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlrpc/raa
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlrpc/sandstorm
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlrpc/tcptunnel
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlrpc/validator
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlrpc/webrick
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlrpc/wwwsrv
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/$f ${RUBY_EXAMPLESDIR}/xmlrpc/$f
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlrpc/test/files
.for f in ${TESTS}
	${INSTALL_DATA} ${WRKSRC}/test/$f ${RUBY_EXAMPLESDIR}/xmlrpc/test/$f
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
