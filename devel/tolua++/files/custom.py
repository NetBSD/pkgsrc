CCFLAGS = ['-I@PREFIX@/include', '-O2', '-ansi']
LIBPATH = ['@PREFIX@/lib']
LIBS = ['lua', 'm']
LINKFLAGS = ['-Wl,-rpath,@PREFIX@/lib']
tolua_bin = 'tolua++'
tolua_lib = 'tolua++'
TOLUAPP = 'tolua++'
