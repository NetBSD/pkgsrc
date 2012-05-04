#!@SH@

# clj - Clojure launcher script
# Borrowed from https://trac.macports.org/changeset/69628

cljjar='lib/java/clojure/clojure.jar'
cljclass='clojure.main'

dir=$0
while [ -h "$dir" ]; do
  ls=`ls -ld "$dir"`
  link=`expr "$ls" : '.*-> \(.*\)$'`
  
  if expr "$link" : '/.*' > /dev/null; then
    dir="$link"
  else
    dir=`dirname "$dir"`"/$link"
  fi
done

dir=`dirname $dir`
dir=`cd "$dir" > /dev/null && pwd`
cljjar="$dir/../$cljjar"
cp="${PWD}:${cljjar}"

# Add extra jars as specified by `.clojure` file
# Borrowed from <http://github.com/mreid/clojure-framework>
if [ -f .clojure ]; then
  cp=$cp:`cat .clojure`
fi

if [ -z "$1" ]; then
  exec @JAVA_HOME@/bin/java -classpath $cp $cljclass
else
  exec @JAVA_HOME@/bin/java -classpath $cp $cljclass $*
fi
