# make configuration file for @@PKGBASENAME@@

CC=	@@PREFIX@@/@@PKGBASENAME@@/bin/cc -fstack-protector
CPP=	@@PREFIX@@/@@PKGBASENAME@@/bin/cpp
CXX=	@@PREFIX@@/@@PKGBASENAME@@/bin/c++ -fstack-protector

.if exists(/etc/mk.conf)
.include "/etc/mk.conf"
.endif
