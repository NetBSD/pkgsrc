# make configuration file for @@PKGNAME@@

CC=	@@PREFIX@@/@@PKGNAME@@/bin/cc -fstack-protector
CPP=	@@PREFIX@@/@@PKGNAME@@/bin/cpp
CXX=	@@PREFIX@@/@@PKGNAME@@/bin/c++ -fstack-protector

.if exists(/etc/mk.conf)
.include "/etc/mk.conf"
.endif
