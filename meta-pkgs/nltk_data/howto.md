# Sources

Fetch https://www.nltk.org/nltk_data/ which is an XML file with an XSL
stylesheet

    wget -O nltk_data.xml  https://www.nltk.org/nltk_data/

should work.
This file contains one line per data, as of 2021-11-24 there are 108 entries,
and some meta package information.

# Generating the packages

Update the date in `split.py` and run it:

	split.py
	
It will generate one package for each entry in the list in textproc/nltk_data-${id}
You'll then need to run 'make mdi' in each directory. If the package existed
before, make sure that the data really changed (distinfo checksums/size differ)
before committing.
